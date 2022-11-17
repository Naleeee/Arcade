# ISound class

## Definition

```cpp
namespace graphic {
    class ISound {
	    public:
		    // CTOR / DTOR
		    ISound() = default;
		    ISound(ISound const &other) = delete;
		    ISound(ISound &&other) = delete;
		    virtual ~ISound() = default;
		    ISound &operator=(ISound const &other) = delete;
		    ISound &operator=(ISound &&other) = delete;

		    // GETTERS
		    virtual float getVolume() const noexcept = 0;

		    // SETTERS
		    virtual void setVolume(float volume) noexcept = 0;
		    virtual void setLoop(bool looping) noexcept = 0;

		    // FUNCTIONS
		    virtual void play() noexcept = 0;
		    virtual void pause() noexcept = 0;
		    virtual void stop() noexcept = 0;
	};
}
```

An inheritance from this class must have a corresponding Window class as `friend`

## Explanation

A sound is an element that can be describe and load with font files (`mp3`, `wav`...)

This element must be playable on the corresponding window type

This sound can be played or stopped

### `setVolume`

This function should set the volume of the sound

This volume must be between `0` and `100`

`0` mean mute and `100` mean max volume

### `getVolume`

This function should return the volume of the sound

This volume is between `0` and `100`

`0` mean mute and `100` mean max volume

### `play`

This function should start playing the sound on a window or resuming it

### `pause`

This function should pause the sound and could be resumed

### `stop`

This function should stop the sound if it's playing on the window

### `setLoop`

This function should change if the sound is looping or not

`false` mean no loop and `true` mean looping the sound
