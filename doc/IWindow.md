# IWindow class

## Definition

```cpp
namespace graphic {
	class IWindow {
	    public:
		    // CTOR / DTOR
		    IWindow() = default;
		    IWindow(IWindow const &other) = delete;
		    IWindow(IWindow &&other) = delete;
		    virtual ~IWindow() = default;
		    IWindow &operator=(IWindow const &other) = delete;
		    IWindow &operator=(IWindow &&other) = delete;

		    // GETTERS
		    virtual FVector getSize() const noexcept = 0;
		    virtual Input getInput() noexcept = 0;

		    // FUNCTIONS
		    virtual void clear() noexcept = 0;
		    virtual void refresh() noexcept = 0;
		    virtual void draw(IImage &) noexcept = 0;
		    virtual void draw(IText &) noexcept = 0;
	};
}
```

## Explanation

A window is an element that can display images, texts or display sounds

### `getSize`

Return the size of the window (`FVector` defined [here](FVector.md))

### `clear`

This function should clear the window

The cleared window could appear as you want but should clear all previously
drawed elements

### `refresh`

This function should refresh the window display to make elements that have
been drawed before a `clear` call visible

### `draw`

This function should draw an element on the window

This element can be an image(`IImage`) or a text(`IText`)

### `getInput`

Return the input from a queue of the user entries as a `input`

`Input` is defined [here](Input.md)
