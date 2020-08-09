#pragma once
#include "mgpch.h"

#include "Magma/Core.h"

namespace Magma {

	class Layer;

	class MAGMA_API LayerStack {
	
		using LayerStackCollection = std::vector<Layer*>;
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* overlay);
		void PopOverlayer(Layer* overlay);
	
		LayerStackCollection::iterator begin() { return layers.begin(); }
		LayerStackCollection::iterator r_begin() { return layers.end(); }

		LayerStackCollection::iterator end() { return layers.end(); }
		LayerStackCollection::iterator r_end() { return layers.begin(); }
	
	private:
		LayerStackCollection layers;
		LayerStackCollection::iterator layersInsert;
	};

}
