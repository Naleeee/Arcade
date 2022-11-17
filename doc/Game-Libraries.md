# Game Libraries documentation

## Game libraries structuration

Game libraries are used to run games with a [graphic library](Graphic-Libraries.md)

Game libraries can call to compatible graphic libraries to make a graphic game

Their is only a main class, the [AGame class](AGame.md)

## How to do a new game library

Your game library must have a static factory as `extern` that have
following methods

```cpp
namespace game {
	class IGameFactory {
	    public:
		    // CTOR / DTOR
		    IGameFactory() = default;
		    IGameFactory(IGameFactory const &other) = delete;
		    IGameFactory(IGameFactory &&other) = default;
		    virtual ~IGameFactory() = default;
		    IGameFactory &operator=(IGameFactory const &other) = delete;
		    IGameFactory &operator=(IGameFactory &&other) = default;

		    // FUNCTIONS
		    virtual std::unique_ptr<AGame> createGame(Player &, IWindow &, IGraphicFactory &) const = 0;
	};
}
```

This functions should return an object with it ownership (`std::unique_ptr`)

This functions could throw an [error](Errors.md)

---

A game library should only use a compatible
[graphic library](Graphic-Libraries.md) to display
