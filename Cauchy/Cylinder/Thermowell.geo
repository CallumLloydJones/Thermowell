//+
SetFactory("OpenCASCADE");
//+
Circle(1) = {0, 0, 0, 0.005, 0, 2*Pi};
//+
Curve Loop(1) = {1};
//+
Plane Surface(1) = {1};
//+
Extrude {0, 0, 0.05} {
  Surface{1}; Layers{20};
}
//+
Physical Surface("Thermowell") += {3, 2};
//+
Physical Surface("Bottom") = {1};


//+
Physical Volume("internal") = {1};
