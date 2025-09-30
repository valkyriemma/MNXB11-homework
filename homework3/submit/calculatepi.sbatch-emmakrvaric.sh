#!/bin/sh

#SBATCH -J "MNXB11 Pi homework3"
#SBATCH --time=00:07:25
#SBATCH -A hep2023-1-6
#SBATCH --mem 26566256k

# Launch the wrapper script 
runincontainer.sh
