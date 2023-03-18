'''
batch normalize and copy all wav files found in folder using sox.

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

if not input("found {0} .wav-files in {1}. Normalize? (y/n) ".format(len(list_of_wavs), os.getcwd())).__eq__('y'):
    quit()

norm_by = 1
while norm_by > 0:
    norm_by = int(input("enter target gain (<= 0) dB: "))


for wav in list_of_wavs:
    print("normalizing {0}...".format(wav), end=None)
    subprocess.call("sox --norm={0} {1} {2}_norm.wav".format(norm_by, wav, wav[:-4]), shell=True)
    print("done")
