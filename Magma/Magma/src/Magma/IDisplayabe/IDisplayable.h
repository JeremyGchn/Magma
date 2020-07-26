#pragma once
#include "Magma/Core.h"

#include <string>

namespace Magma {

	class MAGMA_API IDisplayable {
	
	public:
		virtual const std::string ToString() const = 0;
	};

}
