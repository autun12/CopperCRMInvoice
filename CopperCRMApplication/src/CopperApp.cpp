#include <CopperCRMRenderer.h>
#include <CopperCRMRenderer/Core/EntryPoint.h>

#include "CopperLayer.h"

namespace CopperCRMRenderer {
class CopperCRMApplication : public Application {
public:
	CopperCRMApplication() : Application("Copper CRM") {
		PushLayer(new CopperLayer());
	}

	~CopperCRMApplication() {}
};

Application* CreateApplication() {
	return new CopperCRMApplication();
}

}
