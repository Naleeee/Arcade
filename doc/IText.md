# IText class

## Definition

```cpp
namespace graphic {
	class IText {
	    public:
		    // CTOR / DTOR
		    IText() = default;
		    IText(IText const &other) = delete;
		    IText(IText &&other) = delete;
		    virtual ~IText() = default;
		    IText &operator=(IText const &other) = delete;
		    IText &operator=(IText &&other) = delete;

		    // GETTERS
		    virtual FVector getPosition() const noexcept = 0;
		    virtual float getScale() const noexcept = 0;
		    virtual FVector getSize() const noexcept = 0;
		    virtual float getRotation() const noexcept = 0;
		    virtual std::string getText() const noexcept = 0;
		    virtual Color getColor() const noexcept = 0;

		    // SETTERS
		    virtual void setPosition(FVector position) noexcept = 0;
		    virtual void setRotation(float rotation) noexcept = 0;
		    virtual void setText(std::string text) noexcept = 0;
		    virtual void setColor(const Color &color) noexcept = 0;

		    // FUNCTIONS
		    virtual void move(FVector vector) noexcept = 0;
		    virtual void scale(float scale) noexcept = 0;
		    virtual void rotate(float rotation) noexcept = 0;
		    virtual void fitSize(FVector size) noexcept = 0;
	};
}
```

An inheritance from this class must have a corresponding Window class as `friend`

## Explanation

A text is an element that can be describe and load with font files (`ttf`...)

This element must be drawable on the corresponding window type

This text can be moved, rotated and scaled

### `setPosition`

This function should set the position of the text on a window to the given position

This position is a FVector with two values, a position on the x axis and another
on the y axis

### `fitSize`

This function should set the size of the image

The `size` parameter is the a size of the box the image should fit in
without being differently scaled from x and y

### `setRotation`

This function should set the rotation of an text

The `rotation` argument is in degrees

So its value should be between `-360.0` and `360.0`

### `move`

Move an text of `FVector` distances

`x` and `y` are distance on the x axis and y axis

This values can be positive or negative

### `rotate`

Rotate an text in degrees

So its value should be between `-360.0` and `360.0`

### `getPosition`

Return the position of the text as a `FVector` defined [here](FVector.md)

### `getSize`

Return the width of the text

### `getScale`

Return the scale that as been does since the last `fitSize` call

### `getRotation`

Return the rotation that as been done on the text

### `setText`

Set the text of the text element

### `getText`

Return the text that is displayed by the element

### `setColor`

Set the color of the text, `Color` is defined [here](Color.md)

### `getColor`

Return the color of the text, `Color` is defined [here](Color.md)
