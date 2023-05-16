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

files_in_dir = os.listdir('.')
files_found = []

ending = "."+input("choose file type, e.g. 'wav': ")
print("searching for files ending with {0}:".format(ending))

# find files in dir:
for file in files_in_dir:
    if file[-4:].__eq__(ending):
        print("found", file)
        files_found.append(file)

if len(files_found) < 1:
    print("no {0} files found".format(ending))
    quit()

if not input("This will rename all found files ({0}) in {1}. - ARE YOU SURE? (y/n)".format(len(files_found), os.getcwd())).__eq__('y'):
    quit()

append_samplerate = False
sr = ''

append_samplerate = input('append samplerate to filename? (y/n)').__eq__('y')
##################################### wav #############################

if ending == (".wav"):

    # 1. run a shell command
    for file in files_found:
        # 2. run mediainfo "$file"
        mediainfo = str(subprocess.check_output(["mediainfo " + file], shell=True))
        mediainfo = re.sub(' +', ' ', mediainfo)  # remove surplus spaces
        mediainfo = mediainfo.split("\\n")
        # print(mediainfo)
        # 3. get mediainfo Encoded date:
        for entry in mediainfo:
            if entry.__contains__('Encoded date '):
                entry = entry.split(':', 1)
                entry[0] = entry[0].strip()  # remove whitespaces at start+end
                entry[1] = entry[1].strip()  # remove whitespaces at start+end
                entry[1] = entry[1].split("UTC")[1]
                entry[1] = entry[1].strip()  # remove whitespaces at start+end

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
            print("renaming {0}{3} to {1}_{0}_{2}{3}".format(file[:-4], datestring, sr, ending))
            subprocess.call(["mv {0}{3} {1}_{0}_{2}{3}".format(file[:-4], datestring, sr, ending)], shell=True)

        # standard output:
        else:
            print("renaming {0} to {1}_{0}".format(file, datestring))
            subprocess.call(["mv {0} {1}_{0}".format(file, datestring)], shell=True)


##################################### mp3 #############################
elif ending == (".mp3"):

    print("processing mp3 files with os.path.getmtime()...")

    for file in files_found:
        print("processing", file)
        # 1. convert to date format %Y-%m-%d_%H-%M-%S:
        timestamp = os.path.getmtime(os.path.join(os.getcwd(),file))
        utctime = datetime.datetime.utcfromtimestamp(timestamp).strftime('%Y-%m-%d_%H-%M-%S')
        datestring = utctime

        # 2. run mediainfo "$file"
        mediainfo = str(subprocess.check_output(["mediainfo " + file], shell=True))
        mediainfo = re.sub(' +', ' ', mediainfo)  # remove surplus spaces
        mediainfo = mediainfo.split("\\n")

        for entry in mediainfo:
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
            print("renaming {0}{3} to {1}_{0}_{2}{3}".format(file[:-4], datestring, sr, ending))
            subprocess.call(["mv {0}{3} {1}_{0}_{2}{3}".format(file[:-4], datestring, sr, ending)], shell=True)

        # standard output:
        else:
            print("renaming {0} to {1}_{0}".format(file, datestring))
            subprocess.call(["mv {0} {1}_{0}".format(file, datestring)], shell=True)
