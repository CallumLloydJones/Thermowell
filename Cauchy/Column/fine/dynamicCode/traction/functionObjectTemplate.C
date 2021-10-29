/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
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

\*---------------------------------------------------------------------------*/

#include "functionObjectTemplate.H"
#include "fvCFD.H"
#include "unitConversion.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(tractionFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    tractionFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 5648290fc188b2f25a2484b64da9bc86a3f32b94
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void traction_5648290fc188b2f25a2484b64da9bc86a3f32b94(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

const fvMesh& tractionFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

tractionFunctionObject::tractionFunctionObject
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    functionObjects::regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

tractionFunctionObject::~tractionFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool tractionFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        printMessage("read traction");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool tractionFunctionObject::execute()
{
    if (false)
    {
        printMessage("execute traction");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool tractionFunctionObject::write()
{
    if (false)
    {
        printMessage("write traction");
    }

//{{{ begin code
    #line 122 "/mnt/c/Users/callu/OpenFoam-cases/Cauchy/Column/fine/system/controlDict.functions.traction"
const volVectorField& U = mesh().lookupObject<volVectorField>("U");
       const volScalarField& p = mesh().lookupObject<volScalarField>("p");   	  

       dimensionedScalar nu("nu", dimensionSet(0,2,-1,0,0,0,0), 1.004e-06);
       dimensionedScalar rho("rho",dimensionSet(1,-3,0,0,0,0,0), 1000);	  
	   
	   volTensorField gradU( "gradU", fvc::grad(U) );
       volTensorField sigma( "sigma", (-rho*p*tensor::I) + (nu*rho*(gradU+ gradU.T())) );
	   
		surfaceVectorField traction
		(
			IOobject
			(
				"traction",
				mesh().time().timeName(),
				mesh(),
				IOobject::NO_READ,
				IOobject::AUTO_WRITE
			),
			mesh(),
			dimensionedVector("traction", dimensionSet(1,-1,-2,0,0,0,0), vector::zero)
		);
		
        const word patchName = "Thermowell";
        label patchI = mesh().boundaryMesh().findPatchID(patchName);
        const polyPatch& pp = mesh().boundaryMesh()[patchI];

		forAll(mesh().boundary()[patchI], faceI)
              traction.boundaryFieldRef()[patchI][faceI] = ((pp.faceAreas()[faceI]/mag(pp.faceAreas()[faceI])) * (rho.value()*p.boundaryField()[patchI][faceI])) 
			                                             +
			                                            ((pp.faceAreas()[faceI]/mag(pp.faceAreas()[faceI])) & sigma.boundaryField()[patchI][faceI] )     ;

	   traction.write();
//}}} end code

    return true;
}


bool tractionFunctionObject::end()
{
    if (false)
    {
        printMessage("end traction");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

