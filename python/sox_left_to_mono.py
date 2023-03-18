'''
get all .wav-files in folder and export left channel to mono
using sox
author: @dunland
'''

import os
import subprocess

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

print("found", len(list_of_wavs), ".wav- files in", os.getcwd())


for wav in list_of_wavs:
    if not input("processing file {0}: export left channel? (y/n)".format(wav)).__eq__('y'):
        continue
    subprocess.call("sox {0} -c 1 {1}_left.wav remix 1".format(wav, wav[:-4]), shell=True)
    print("done")

print("end of files.")
