# Errors definition

```cpp
namespace arcade {
	class ArcadeError : public std::exception {
	public:
		explicit ArcadeError(std::string message);
		ArcadeError(ArcadeError const &other) = default;
		ArcadeError(ArcadeError &&other) noexcept = default;
		~ArcadeError() noexcept = default;
		ArcadeError &operator=(ArcadeError &&other) noexcept = delete;
		const char *what() const noexcept;

	protected:
		std::string message_;
	};
}
```

## Graphic errors

```cpp
namespace arcade {
	class GraphicError final : public ArcadeError {
	public:
		explicit GraphicError(std::string const &message);
		GraphicError(GraphicError const &other) = default;
		GraphicError(GraphicError &&other) noexcept = default;
		~GraphicError() noexcept = default;
		GraphicError &operator=(GraphicError const &other) noexcept = delete;
		GraphicError &operator=(GraphicError &&other) noexcept = delete;
	};
}
```

Should be thrown when a graphic library failed to loading or initializing

## Game errors

```cpp
namespace arcade {
	class GameError final : public ArcadeError {
	public:
		explicit GameError(std::string const &message);
		GameError(GameError const &other) = default;
		GameError(GameError &&other) noexcept = default;
		~GameError() noexcept = default;
		GameError &operator=(GameError const &other) noexcept = delete;
		GameError &operator=(GameError &&other) noexcept = delete;
	};
}
```

Should be thrown when a game library failed to loading or initializing
