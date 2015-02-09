waves2Foam - A Wave Generation Toolbox
======================================

The library waves2Foam is a toolbox used to generate and absorb free surface water waves. Currently the method applies the relaxation zone technique (active sponge layers) and a large range of wave theories are supported and the relaxation zones can take arbitrary shapes.

The library also comes with pre- and postprocessing utilities tailored for use for free surface flows within the fields of coastal, marine and maritime engineering.


Further modifications
=====================

Original source came from here: svn://svn.code.sf.net/p/openfoam-extend/svn/trunk/Breeder_1.6/other/waves2Foam/ 

Modificiations made by Bruno Santos <wyldckat@github> for blueCFD/blueCFD-Core:
   - Adapted the source code to build on blueCFD 2.3-1 and 2.1-2.


Building on blueCFD 2.3-1 and 2.1-2
===================================

Using Git
---------

You need to have [MSys+Git](http://msysgit.github.io/) installed (already installed by default in blueCFD-Core 2.3), in order to use Git on Windows.

  1. Go to your user folder:

     ```
     mkdir -p $FOAM_RUN
     cd $FOAM_RUN/..
     ```

  2. Clone the repository and go into the cloned repository:

     ```
     git clone https://github.com/blueCFD/waves2Foam.git
     cd waves2Foam
     ```

  3. Checkout the repository respective to the version of OpenFOAM you are using:

   * blueCFD-Core 2.3-1:

     ```
     git checkout blueCFD-Core-2.3-1
     ```

   * blueCFD 2.1-2:

     ```
     git checkout blueCFD-2.1-2
     ```

   4. Get and build GSL by running the following commands:

     ```
     cd gsl
     ./getNBuildGSL > log.make 2>&1
     ```
     
     It will take a considerable time to build GSL. You can inspect the contents of the file `log.make` while the script is running, to see how it's coming along.
     
   5. Go back to the main folder `waves2Foam`:
   
     ```
     cd ..
     ```

   6. Build all of the libraries and utilities by running:

     ```
     ./Allwmake
     ```

   7. The tutorials are available at the folder `tutorials`.


Using Zip
---------

  1. Go to your user folder:

     ```
     mkdir -p $FOAM_RUN
     cd $FOAM_RUN/..
     ```

  2. Get the Zip file for the repository respective to the version of blueCFD/blueCFD-Core you are using:

   * blueCFD-Core 2.3-1:

     ```
     wget https://github.com/blueCFD/waves2Foam/archive/blueCFD-Core-2.3-1.zip
     ```

   * blueCFD 2.1-2:

     ```
     wget https://github.com/blueCFD/waves2Foam/archive/blueCFD-2.1-2.zip
     ```

   3. Unzip the respective file and go into the respective folder, for example:

     ```
     unzip blueCFD-Core-2.3-1.zip
     cd waves2Foam-blueCFD-Core-2.3-1
     ```

   4. Get and build GSL by running the following commands:

     ```
     cd gsl
     ./getNBuildGSL > log.make 2>&1
     ```
     
     It will take a considerable time to build GSL. You can inspect the contents of the file `log.make` while the script is running, to see how it's coming along.
     
   5. Go back to the main folder `waves2Foam`:
   
     ```
     cd ..
     ```

   6. Build all of the libraries and utilities by running:

     ```
     ./Allwmake
     ```

   7. The tutorials are available at the folder `tutorials`.



INSTALLATION On Linux
=====================

Please use the original source code for compiling on Linux, or at least do a `git checkout master`.


DOCUMENTATION
=============

The following paper describes the implementation of boundary conditions, the relaxation zones 
and the framework for relaxationShapes:

@article { jacobsenFuhrmanFredsoe2012,
    Author = {Jacobsen, N G and Fuhrman, D R and Freds\o{}e, J},
    title = {{A Wave Generation Toolbox for the Open-Source CFD Library: OpenFoam\textregistered{}}},
    Journal = {{Int. J. for Numer. Meth. Fluids}},
    Year = {2012},
    Volume = {70},
    Number = {9},
    Pages = {1073-1088},
    DOI = {{10.1002/fld.2726}},
}

Please make prober referencing to it, when using the toolbox.

The porosity module and the calibration of the resistance coefficients are described in

@article{Jensen2014,
    Author = {Jensen, Bjarne and Jacobsen, Niels Gj\o{}l and Christensen, Erik Damgaard},
    Journal = {Coastal Engineering},
    Pages = {56--72},
    Publisher = {Elsevier B.V.},
    Title = {{Investigations on the porous media equations and resistance coefficients for coastal structures}},
    Volume = {84},
    Year = {2014},
}

Furthermore, users are referred to:

http://openfoamwiki.net/index.php/Contrib/waves2Foam


License
=======

The same as OpenFOAM(R), namely GNU GPL v3. For more information, see the file COPYING.

