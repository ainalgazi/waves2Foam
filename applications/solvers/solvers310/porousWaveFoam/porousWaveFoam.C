/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     |
    \\  /    A nd           | For copyright notice see file Copyright
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Application
    interFoam

Description
    Solver for 2 incompressible, isothermal immiscible fluids using a VOF
    (volume of fluid) phase-fraction based interface capturing approach.

    The momentum and other fluid properties are of the "mixture" and a single
    momentum equation is solved.

    Turbulence modelling is generic, i.e.  laminar, RAS or LES may be selected.

    For a two-fluid approach see twoPhaseEulerFoam.

    This solver has on top of the standard OpenFoam version been added a method
    for wave generation and relaxation.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "MULES.H"
#include "subCycle.H"
#include "interfaceProperties.H"
#include "twoPhaseMixture.H"
#include "turbulenceModel.H"

#include "relaxationZone.H"
//#include "porosityZones.H"
#include "wavesPorosityModel.H"
#include "externalWaveForcing.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
#   include "setRootCase.H"
#   include "createTime.H"
#   include "createMesh.H"
#   include "readGravitationalAcceleration.H"
#   include "readWaveProperties.H"
#   include "createExternalWaveForcing.H"
#   include "createPorosityFields.H"
#   include "readPIMPLEControls.H"
#   include "initContinuityErrs.H"
#   include "createFields.H"
#   include "readTimeControls.H"
#   include "correctPhi.H"
#   include "CourantNo.H"
#   include "setInitialDeltaT.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.run())
    {
#       include "readPIMPLEControls.H"
#       include "readTimeControls.H"
#       include "CourantNo.H"
#       include "setDeltaT.H"

        runTime++;

        Info<< "Time = " << runTime.timeName() << nl << endl;

        externalWave->step();

#       include "calcPorosity.H"

        twoPhaseProperties.correct();

#       include "alphaEqnSubCycle.H"

        relaxing.correct();

#       include "UEqn.H"

        // --- PISO loop
        for (int corr = 0; corr < nCorr; corr++)
        {
#           include "pEqn.H"
        }

#       include "continuityErrs.H"

        p = pd + rho*gh;

        if (pd.needReference())
        {
            p += dimensionedScalar
            (
                "p",
                p.dimensions(),
                pRefValue - getRefCellValue(p, pdRefCell)
            );
        }

        turbulence->correct();

        runTime.write();

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
