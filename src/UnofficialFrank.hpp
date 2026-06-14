#include "rack.hpp"

using namespace rack;

// Forward-declare the Plugin, defined in Template.cpp
extern Plugin *pluginInstance;

// Forward-declare each Model, defined in each module source file
extern Model *modelFrankBussFormula;

// make those precise in hp and u rack units
float hp(float w, bool mhp = false);
float u(float h, bool mhp = false);
Vec hpu(float w, float h, bool mhpw = false, bool mhph = false);

void screws(ModuleWidget* widget, float hp);

void port(ModuleWidget* w, Module* m, Vec pos, int portId, bool isInput, const char* name);
void button(ModuleWidget* w, Module* m, Vec pos, int buttId, int lightId, const char* name);
void okNo(ModuleWidget* w, Module* m, Vec pos, int portId, const char* name);
void knob(ModuleWidget* w, Module* m, Vec pos, int paramId, const char* name);
