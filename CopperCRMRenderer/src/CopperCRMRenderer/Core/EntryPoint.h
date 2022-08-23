#pragma once

extern CopperCRMRenderer::Application* CopperCRMRenderer::CreateApplication();

int main(int argc, char** argv) {
	CopperCRMRenderer::Log::Init();
	auto app = CopperCRMRenderer::CreateApplication();
	app->Run();
	delete app;
}