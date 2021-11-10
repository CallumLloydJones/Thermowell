//+
SetFactory("OpenCASCADE");
//+
Circle(1) = {0, 0, 0, 0.01, 0, 2*Pi};
//+
Circle(2) = {0, 0, 0, 0.0085, 0, 2*Pi};
//+
//+
Extrude {0, 0, 0.05} {
  Curve{1}; Layers{12}; 
}
//+
Extrude {0, 0, 0.047} {
  Curve{2}; Layers{11}; 
}
//+
Curve Loop(3) = {1};
//+
Curve Loop(4) = {2};
//+
Plane Surface(3) = {3, 4};
//+
Curve Loop(5) = {4};
//+
Plane Surface(4) = {5};
//+
Curve Loop(6) = {6};
//+
Plane Surface(5) = {6};
//+
Physical Surface("Thermowell") = {4, 1};
//+
Physical Surface("Bottom") = {3};
//+
Physical Surface("Inside") = {2, 5};
//+
Surface Loop(1) = {4, 1, 3, 2, 5};
//+
Volume(1) = {1};
//+
Physical Volume("internal") = {1};
