# VulkanWrapper

VulkanWrapper (VKW) is C++ wrapper for the Vulkan API. It adds C++ concepts like RAII and move semantics to ease the management of Vulkan objects. When a VKW object goes out of scope, it's destructor destroys the underlying Vulkan object. For example:

```c++
{
    vk::Instance instance = createInstance(...);
    //instance will be automatically destroyed at the end of scope
}
```

VKW objects work with standard memory management types. For example:

```c++
std::unique_ptr<vk::Instance> instance = std::make_unique<vk::Instance>(...);
std::shared_ptr<vk::Image> image = loadImage(...);
```

VKW objects are movable. For example:

```c++
class MyImage {
    vk::Image image;
    
public:
    MyImage(vk::Image&& image)
    : image(std::move(image))
    {
        //image parameter moved into member
    }
}
```

Vulkan enum types are wrapped in C++ enum classes, providing type safety without polluting a namespace.

VKW uses the `vk` namespace, so it will conflict with other C++ libraries, like [Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp).

VKW is still in alpha, so breaking changes will happen without warning.
