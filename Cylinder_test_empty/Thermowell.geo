circleDots=05;     // coarse:5     fine:12
heightLayers=20;   // coarse:20    fine:35
r=0.005;
h=0.05;

/////////////////////////////
Point(1) = {0, 0, 0};
Point(2) = {r, 0, 0};
Point(3) = {0, r, 0};
Point(4) = {-r, 0, 0};
Point(5) = {0, -r, 0};
//+
Circle(1) = {4, 1, 3};
Circle(2) = {3, 1, 2};
Circle(3) = {2, 1, 5};
Circle(4) = {5, 1, 4};
Line Loop(1) = {4, 1, 2, 3};
Plane Surface(1) = {1};
//+
Transfinite Line {1, 2, 3, 4} = circleDots Using Progression 1;
//+
Extrude {0, 0, h} {
  Surface{1}; Layers{heightLayers};
}
//+
Transfinite Surface {1} Alternate;
//+ the following does not work yet
Transfinite Surface {25} = {6, 5, 2, 18} Alternate;
Transfinite Surface {13} = {6, 5, 4, 8} Alternated;
Transfinite Surface {17} = {13, 3, 4, 8} Alternated;
Transfinite Surface {21} = {13, 18, 2, 3} Alternated;
//+
Physical Surface("Bottom") = {1};
Physical Surface("Thermowell") = {13, 17, 21, 25, 26};
Physical Volume("domain") = {1};
//+

