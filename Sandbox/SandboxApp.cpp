#include <JMEngine.h>
#include <App/EntryPoint.h>
#include "Scenes/Scene3D.h"
#include "Scenes/GraphicsScene.h"
#include "Scenes/CubeGame/CubeGame.h"
#include "Scenes/Scene2D.h"
#include "Scenes/SceneLuaTest.h"
#include "Scenes/SceneModelViewer.h"
#include "Scenes/SceneSelect.h"


using namespace jm;

class Game : public Application
{
public:
	Game(WindowProperties windowProperties) : Application(windowProperties, RenderAPI::VULKAN)
	{
	}

	~Game()
	{
	}

	void Init() override
	{
		Application::Init();

		const String root = ROOT_DIR;
		jm::VFS::Get()->Mount("Meshes", root + "/Sandbox/res/meshes");
		jm::VFS::Get()->Mount("Textures", root + "/Sandbox/res/textures");
		jm::VFS::Get()->Mount("Sounds", root + "/Sandbox/res/sounds");


		GetSceneManager()->EnqueueScene(new SceneSelect("SceneSelect"));
		GetSceneManager()->EnqueueScene(new SceneLuaTest("Lua Test Scene"));
		GetSceneManager()->EnqueueScene(new CubeGame("Cube Game Scene"));
		GetSceneManager()->EnqueueScene(new SceneModelViewer("SceneModelViewer"));
		GetSceneManager()->EnqueueScene(new Scene3D("Physics Scene"));
		GetSceneManager()->EnqueueScene(new GraphicsScene("graphics Scene"));
		GetSceneManager()->JumpToScene(4);
	}
};

jm::Application* jm::CreateApplication()
{
    System::CFG cfg(ROOT_DIR"/Sandbox/Settings.cfg");
    const WindowProperties windowProperties(cfg);

    return new Game(windowProperties);
}