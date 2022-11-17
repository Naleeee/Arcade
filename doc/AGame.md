# AGame class

## Definition

```cpp
	class AGame {
	    public:
		    // CTOR / DTOR
		    AGame() = delete;
		    AGame(Player &, IWindow &, IGraphicFactory &);
		    AGame(AGame const &other) = delete;
		    AGame(AGame &&other) = delete;
		    virtual ~AGame() noexcept = default;
		    AGame &operator=(AGame const &other) = delete;
		    AGame &operator=(AGame &&other) = delete;

		    // FUNCTIONS
		    virtual bool handleInput(const Input &) noexcept = 0;
		    virtual void refresh() noexcept = 0;

	    protected:
		    Player &player;
		    IWindow &window;
		    IGraphicFactory &graphicFactory;
	};
```

## Explanation

A game is a class that can run an entire game just by interacting with
a [graphic library](Graphic-Libraries.md)

### Constructor

This constructor must be on the child class

### `handleInput`

This function should treat the input returned by the corresponding
 window and update the game

This function return `false` when the game should by exited and `true`
on every other cases

### `refresh`

This function should internaly update the game and refresh the displayed
elements on the specified window
