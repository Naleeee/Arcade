# Graphic Libraries documentation

## Graphic libraries structuration

Graphic libraries are used to display elements on the screen

This libraries should not be use for anything else than user interactions

Graphic libraries can display images, texts and play sounds

They are splitted in 4 classes

- Window class (inherit from [IWindow](IWindow.md))

- Image class (inherit from [IImage](IImage.md))

- Text class (inherit from [IText](IText.md))

- Sound class (inherit from [ISound](ISound.md))

## How to do a new graphic library

Your graphic library must have a static factory as `extern` that have
the following methods

```cpp
namespace graphic {
	class IGraphicFactory {
	    public:
		    // CTOR / DTOR
		    IGraphicFactory() = default;
		    IGraphicFactory(IGraphicFactory const &other) = delete;
		    IGraphicFactory(IGraphicFactory &&other) = default;
		    virtual ~IGraphicFactory() = default;
		    IGraphicFactory &operator=(IGraphicFactory const &other) = delete;
		    IGraphicFactory &operator=(IGraphicFactory &&other) = default;

		    // FUNCTIONS
		    virtual std::unique_ptr<IWindow> createWindow(std::string_view) const = 0;
		    virtual std::unique_ptr<IImage> createImage(std::string_view filePath) const = 0;
		    virtual std::unique_ptr<IText> createText(std::string_view filePath) const = 0;
		    virtual std::unique_ptr<ISound> createSound(std::string_view filePath) const = 0;
	};
}
```

This functions should return an object with it ownership (`std::unique_ptr`)

`filePath` is the path where to load texture, font or sound from

This functions could throw an [error](Errors.md)

This factory should be returned by a function that is prototyped as followed

```cpp
extern "C" std::unique_ptr<IGraphicFactory> createGraphicFactory(char* env[]);
```

To do this, you need to make inheritance from this four classes

Here are the definitions of this 4 abstract classes

[IWindow](IWindow.md)

[IImage](IImage.md)

[IText](IText.md)

[ISound](ISound.md)
