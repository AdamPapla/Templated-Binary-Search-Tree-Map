# Templated implementation of a binary search tree map  
## Based on the implementation of `std::map`  

This project provides a simple templated map class, which provides most of the main functionalities of `std::map`, including:  
- `Map::at`: Checks if a key is in the map. If so, returns a reference to the value. If not, throws an out of range exception.
- `Map::insert`: Inserts a key value pair into the map.
- `Map::operator[]`: Used for writing/accessing a value corresponding to a key. If no such key is found, one is inserted.
- `Map::display`: Prints all key-value pairs of the map in order.
- `Map::search`: Checks if element is in the map. Returns a bool. 

