# IImage class

## Definition

```cpp
namespace graphic {
	class IImage {
	    public:
		    // CTOR / DTOR
		    IImage() = default;
		    IImage(IImage const &other) = delete;
		    IImage(IImage &&other) = delete;
		    virtual ~IImage() = default;
		    IImage &operator=(IImage const &other) = delete;
		    IImage &operator=(IImage &&other) = delete;

		    // GETTERS
		    virtual FVector getPosition() const noexcept = 0;
		    virtual FVector getSize() const noexcept = 0;
		    virtual float getScale() const noexcept = 0;
		    virtual float getRotation() const noexcept = 0;

		    // SETTERS
		    virtual void setPosition(FVector position) noexcept = 0;
		    virtual void setRotation(float rotation) noexcept = 0;
		    virtual void setTexture(std::string_view filePath) = 0;

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

An image is an element that can be describe and load with images files (`png`, `jpeg`...)

This element must be drawable on the corresponding window type

This image can be moved, rotated and scaled

### `setPosition`

This function should set the position of the image on a window to the given position

This position is a FVector with two values, a position on the x axis and
another on the y axis

### `fitSize`

This function should set the size of the image

The `size` parameter is the a size of the box the image should fit in
without being differently scaled from x and y

### `setRotation`

This function should set the rotation of an image

The `rotation` argument is in degrees

So its value should be between `-360.0` and `360.0`

### `move`

Move an image of `FVector` distances

`x` and `y` are distance on the x axis and y axis

This values can be positive or negative

### `rotate`

Rotate an image in degrees

So its value should be between `-360.0` and `360.0`

### `getPosition`

Return the position of the image as a `FVector` defined [here](FVector.md)

### `getSize`

Return the width of the image

### `getScale`

Return the scale that as been does since the last `fitSize` call

### `getRotation`

Return the rotation that as been done on the image

### `setTexture`

Change the texture of the image to the `filePath` file given as argument
