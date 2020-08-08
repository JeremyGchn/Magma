#pragma once
#include "mgpch.h"
#include "Magma/Core.h"

namespace Magma {

	class MAGMA_API IDisplayable {
	
	public:
		virtual const std::string ToString() const = 0;
	};

	static std::ostream& operator << (std::ostream& os, const IDisplayable& displayable) {
		os << displayable.ToString();
		return os;
	}

}
