//+
l = 1;   // base length
n = 8;   // number of nodes on base edges
Point(1) = {0, 0, 0, 1.0};
Point(2) = {l, 0, 0, 1.0};
Point(3) = {0, l, 0, 1.0};
Point(5) = {l, l, 0, 1.0};
//+
Line(1) = {3, 5};
//+
Line(2) = {5, 2};
//+
Line(3) = {2, 1};
//+
Line(4) = {1, 3};
//+
Curve Loop(1) = {4, 1, 2, 3};
//+
Plane Surface(1) = {1};

Extrude {0, 0, 6} {
  Surface{1}; Layers{6*n};
}
Transfinite Surface {1, 26} Alternate;
Transfinite Curve {1, 4, 3, 2, 6, 7, 8, 9} = n Using Progression 1;
Transfinite Surface {17,21,13,25} Alternate;//+
Physical Surface("fixed") = {1};
//+
Physical Surface("free") = {25, 26, 17, 21, 13};
//+
Physical Volume("domain") = {1};
