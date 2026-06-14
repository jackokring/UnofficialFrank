#include "UnofficialFrank.hpp"


Plugin *pluginInstance;


void init(Plugin *p) {
	pluginInstance = p;

	// Add all Models defined throughout the plugin
	p->addModel(modelFrankBussFormula);

}

// make those precise in hp and u rack units
float hp(float w, bool mhp) {
	return (mhp ? w - 1 : w) * RACK_GRID_WIDTH;
}

float u(float h, bool mhp) {
	return h * RACK_GRID_HEIGHT / 3.0f - (mhp ? RACK_GRID_WIDTH : 0);
}

Vec hpu(float w, float h, bool mhpw, bool mhph) {
	return Vec(hp(w, mhpw), u(h, mhph));
}

void screws(ModuleWidget* widget, float hp) {
    widget->addChild(createWidget<ScrewSilver>(hpu(1, 0)));
	widget->addChild(createWidget<ScrewSilver>(hpu(hp, 0, true)));
	widget->addChild(createWidget<ScrewSilver>(hpu(1, 3, false, true)));
	widget->addChild(createWidget<ScrewSilver>(hpu(hp, 3, true, true)));
}


void port(ModuleWidget* w, Module* m, Vec pos, int portId, bool isInput, const char* name) {
	if(isInput) {
		w->addInput(createInput<PJ301MPort>(pos, m, portId));
	} else {
		w->addOutput(createOutput<PJ301MPort>(pos, m, portId));
	}
}

void button(ModuleWidget* w, Module* m, Vec pos, int buttId, int lightId, const char* name) {
	w->addParam(createParam<LEDButton>(pos, m, buttId));
	w->addChild(createLight<MediumLight<GreenLight>>(pos, m, lightId));
}

void okNo(ModuleWidget* w, Module* m, Vec pos, int portId, const char* name) {
	w->addChild(createLight<MediumLight<GreenRedLight>>(pos, m, portId));
}

void knob(ModuleWidget* w, Module* m, Vec pos, int paramId, const char* name) {
	w->addParam(createParam<RoundBlackKnob>(pos, m, paramId));
}
