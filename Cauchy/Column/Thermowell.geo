//+
SetFactory("OpenCASCADE");
//+
Rectangle(1) = {-0.005, -0.005, 0, 0.01, 0.01, 0};
//+
Curve Loop(1) = {1};
//+
Plane Surface(1) = {1};
//+
Extrude {0, 0, 0.05} {
  Surface{1}; Layers{20};
}
//+
Physical Surface("Thermowell") = {4, 2, 6, 3, 5};
//+
Physical Surface("Bottom") = {1};
//+
Physical Volume("internal") = {1};

