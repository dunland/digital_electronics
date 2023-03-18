'''
This script renames all wav-files in current working direction using the Encoding date of mediainfo shell command.
Optionally, the samplerate can be appended to the file.

TODO: normalize using sox

author: @dunland
'''

import os
import subprocess
import re
import datetime

list_of_files = os.listdir('.')
list_of_wavs = []

# find wav files in dir:
for file in list_of_files:
    if file[-4:].__eq__( ".wav"):
        print("found", file)
        list_of_wavs.append(file)

if len(list_of_wavs) < 1:
    print("no wav files found")
    quit()

if not input("This will rename all found wave files ({0}) in {1}. - ARE YOU SURE? (y/n)".format(len(list_of_wavs), os.getcwd())).__eq__('y'):
    quit()

append_samplerate = input('append samplerate to filename? (y/n)').__eq__('y')
sr = ''

mediainfo_dict = {}
# 1. run a shell command
for wav in list_of_wavs:
    # 2. run mediainfo "$file"
    mediainfo = str(subprocess.check_output(["mediainfo " + wav], shell=True))
    mediainfo = re.sub(' +', ' ', mediainfo)  # remove surplus spaces
    mediainfo = mediainfo.split("\\n")
    # print(mediainfo)
    # 3. get mediainfo Encoded date:
    for entry in mediainfo:
        if entry.__contains__('Encoded date '):
            entry = entry.split(':', 1)
            entry[0] = entry[0].strip()  # remove whitespaces at start+end
            entry[1] = entry[1].strip()

            # 4. convert to date format %Y-%m-%d_%H-%M-%S:
            datestring = datetime.datetime.strptime(entry[1], '%Y-%m-%d %H:%M:%S').strftime('%Y-%m-%d_%H-%M-%S')

        if append_samplerate and entry.__contains__('Sampling rate'):
            entry = entry.split(':', 1)
            entry[0] = entry[0].strip()  # remove whitespaces at start+end
            entry[1] = entry[1].strip()
            if entry[1][:2] == '48':
                sr = '48kHz'
            elif entry[1][:2] == '44':
                sr = '44.1kHz'
            elif entry[1][:2] == '96':
                sr = '96kHz'

    # 5. shell: mv "$file" "$date"_"$file"
    # append samplerate:
    if append_samplerate:
        print("renaming {0} to {1}_{0}_{2}.wav".format(wav[:-4], datestring, sr))
        subprocess.call(["mv {0} {1}_{0}_{2}.wav".format(wav[:-4], datestring, sr)], shell=True)

    # standard output:
    else:
        print("renaming {0} to {1}_{0}".format(wav, datestring))
        subprocess.call(["mv {0} {1}_{0}".format(wav, datestring)], shell=True)
