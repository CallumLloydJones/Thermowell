/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    initialConditions_vc

Description
    Generates non-standard initial conditions for test cases.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "pointFields.H"
#include "mathematicalConstants.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"

	/*
    // Point mesh
    pointMesh pMesh(mesh);

    // Read mechanical properties dictionary
    IOdictionary mechanicalProperties
    (
        IOobject
        (
            "mechanicalProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    // Read run parameters dictionary
    IOdictionary runParameters
    (
        IOobject
        (
            "runParameters",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    // Test case name
    const word& tutorial(runParameters.lookupOrDefault<word>("tutorial", "None"));
    Info << "Tutorial name: " << tutorial;

    // Read density
    const dimensionedScalar& rho(mechanicalProperties.lookup("rho"));

    // Read energy
    const dimensionedScalar& E(mechanicalProperties.lookup("E"));

    // Read nu
    const dimensionedScalar& nu(mechanicalProperties.lookup("nu"));

    // Compute mu
    const dimensionedScalar mu = E/(2*(1+nu));

    // Compute lambda
    const dimensionedScalar lambda = (nu*E/((1+nu)*(1 - 2*nu)));

    // Nodal coordinates
    const vectorField& X = mesh.points();

    // Read linear momentum field
    pointVectorField lm
    (
        IOobject
        (
            "lm",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        pMesh,
        dimensionedVector("lm", dimensionSet(1,-2,-1,0,0,0,0), vector::zero)
    );

    if (tutorial == "bendingColumnLM")
    {	
	const dimensionedScalar& dV(runParameters.lookup("V"));
	scalar V = dV.value();
	scalar H = 6;
    	forAll(mesh.points(), node) {
		scalar Y = mesh.points()[node][1];
		lm[node] = rho.value() * (V/H) * vector(Y,0,0);
	}
    }

    lm.write();

    Info<< "\n end\n";

*/

pointMesh pMesh(mesh);

    // Read linear momentum field
    pointVectorField lm
    (
        IOobject
        (
            "lm",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        pMesh,
        dimensionedVector("lm", dimensionSet(1,-2,-1,0,0,0,0), vector::zero)
    );
    	

    forAll(mesh.points(), n){
	scalar X = mesh.points()[n][0], Xd = X - 0.5;
	scalar Y = mesh.points()[n][1], Yd = Y - 0.5;
	scalar Z = mesh.points()[n][2], Zd = Z - 0.5;

	if (Z==0){
		if ((Xd*Xd + Yd*Yd) < 0.25){
			lm[n] = vector(1,0,0);
		}
	}

    }




    lm.write();

	return 0;
}
