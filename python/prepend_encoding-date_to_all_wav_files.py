import os
import subprocess
import re
import datetime

list_of_files = os.listdir('.')
list_of_wavs = []

if not input("This will rename all your .wav-files in {0} - ARE YOU SURE? (y/n)".format(os.getcwd())).__eq__('y'):
    quit()

# find wav files in dir:
for file in list_of_files:
    if file[-4:].__eq__( ".wav"):
        print("found", file)
        list_of_wavs.append(file)

print(list_of_wavs)

if len(list_of_wavs) < 1:
    print("no wav files found")
    quit()

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

    # 5. shell: mv "$file" "$date"_"$file"
    print("renaming {0} to {1}_{0}".format(wav, datestring))
    subprocess.call(["mv {0} {1}_{0}".format(wav, datestring)], shell=True)

