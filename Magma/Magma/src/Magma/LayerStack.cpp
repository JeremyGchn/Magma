#include "mgpch.h"
#include "LayerStack.h"
#include "Layer.h"

namespace Magma{
	
	LayerStack::LayerStack() {
		layersInsert = begin();
	}


	LayerStack::~LayerStack() {
		for (Layer* layer : layers) {
			delete layer;
		}
	}


	void LayerStack::PushLayer(Layer* layer) {
		layersInsert = layers.emplace(layersInsert, layer);
	}


	void LayerStack::PopLayer(Layer* layer) {
		auto it = std::find(begin(), end(), layer);
		if (it != end()) {
			layers.erase(it);
			layersInsert--;
		}
	}


	void LayerStack::PushOverlay(Layer* overlay) {
		layers.emplace_back(overlay);
	}


	void LayerStack::PopOverlayer(Layer* overlay) {
		auto it = std::find(begin(), end(), overlay);
		if (it != end()) {
			layers.erase(it);
		}
	}
}