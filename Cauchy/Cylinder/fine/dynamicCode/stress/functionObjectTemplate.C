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

defineTypeNameAndDebug(stressFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    stressFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 306ffadb80f80af26842c79303e45c0cd2792afe
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void stress_306ffadb80f80af26842c79303e45c0cd2792afe(bool load)
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

const fvMesh& stressFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

stressFunctionObject::stressFunctionObject
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

stressFunctionObject::~stressFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool stressFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        printMessage("read stress");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool stressFunctionObject::execute()
{
    if (false)
    {
        printMessage("execute stress");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool stressFunctionObject::write()
{
    if (false)
    {
        printMessage("write stress");
    }

//{{{ begin code
    #line 87 "/mnt/c/Users/callu/OpenFoam-cases/Cauchy/3D-cylinder-finite/fine/system/controlDict.functions.cauchy"
const volVectorField& U = mesh().lookupObject<volVectorField>("U");
       const volScalarField& p = mesh().lookupObject<volScalarField>("p");
	   
	   volScalarField p_new( "p_new", p );
	   p_new.write();
	   
       const scalar nu =  1.004e-06;
       const scalar rho = 1000;

/*		
       dimensionedTensor sigma
       (
       “sigma”,
       dimeless,
       tensor(1,0,0,0,1,0,0,0,1)
        );
*/
		
		
		
//		volTensorField Sigma = 	(rho*p*tensor::one)+ (2*nu*rho*(symm(fvc::grad(U))));    + fvc::grad(U).T()));
//		Sigma.write();
/*
       volTensorField Sigma
       (
           IOobject
           (
               "Sigma",
               mesh().time().timeName(),
               mesh,
               IOobject::NO_READ,
               IOobject::AUTO_WRITE
           ),

       );
	   */
//}}} end code

    return true;
}


bool stressFunctionObject::end()
{
    if (false)
    {
        printMessage("end stress");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

