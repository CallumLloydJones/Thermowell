from fluidfoam import readmesh
import os

cwd = "C:/Users/callu/OpenFoam-cases/Thermowell/"   # os.getcwd()

coarse = cwd+'/coarse'
fine = cwd+'/fine'

x, y, z = readmesh(coarse)