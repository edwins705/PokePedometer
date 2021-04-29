# Pokemoneter

## Downloading QT Creator Under an Open Source License
Download QT Creator 5 from this [link](https://www.qt.io/download-qt-installer)

## Download Fonts!
Go to the fonts folder and download the fonts!

## Configuring Pokemoneter in QT5
1) File > Open File or Project
2) Navigate to Pokemoneter folder
3) Open Pokemoneter.pro file
4) Under **Projects** on the left toolbar, go to **Run** section under **Build & Run**
5) Set working directory to the Pokemoneter folder
6) Build project (bottom left toolbar)
7) Run project (bottom left toolbar)

## Configure on BU Eng-Grid
1) Transfer the pokemoneter folder to eng-grid 
2) In the pokemoneter folder on eng-grid, run 
```
qmake
```
3) Run
```
make
```
4) To run Qt aapplication on beaglebone, copy pokemoneter executable to beaglebone

## Configure Driver Program for Beaglebone
1) Transfer pokemoneter project folder into eng-grid
2) Locate i2c_controle_b.c and Makefile which is located in step_module folder
3) Run `` make ``to generate i2c executable
4) Copy executable to beaglebone

## Running whole application 
1) Make sure to copy i2c and pokemoneter executable into beaglebone root
2) Create an file named "steps.txt" in root
3) Transfer whole images folder into root 
4) Transfer scripts `` run_poke.sh `` and `` kill_poke.sh `` from run_folder
5) To run application, run `` run_poke.sh ``
6) To end application, run `` kill_poke.sh ``
** Make sure inside your beaglebone, you have your images folder, run_poke.sh, kill_poke.sh, steps.txt, and the pokemoneter and i2c executable files.  

