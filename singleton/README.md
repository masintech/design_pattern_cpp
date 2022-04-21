Making a 'safe singleton is easy  
- Hide or delete the type's constructor, copy constructor and copy assignment operators
- Create a static method that returns a reference to a static member
- Guaranteed to be thread-safe since C++11  
Types with "hard" dependencies on singletons are difficult to test  
- Cannot decouple the singleton and supply a fake object  
Instead of directly using a singleton, consider depending on an abstraction(e.g. an interface)  
Consider defining singleton lifetime in DI container

