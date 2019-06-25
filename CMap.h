#ifndef _CMAP_H_
#define _CMAP_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define data_size	150

typedef struct map
{
	uint32_t key;
	char data[data_size];
} map_s;

class CMap
{
	public:
		CMap(uint16_t map_size);
		~CMap();
		bool insert(uint32_t key, char* data);
		char* find(uint32_t key);
		void remove(uint32_t key);
		uint16_t sizeLeft();
	private:
		uint32_t _map_max_size;
		uint8_t _map_now_index;
		map_s *_map_table_ptr;
};

CMap::CMap(uint16_t map_size) :_map_max_size(map_size), _map_now_index(0)
{
	_map_table_ptr = new map_s[_map_max_size];
}

CMap::~CMap()
{
	delete _map_table_ptr;
}

bool CMap::insert(uint32_t key, char* data) {
	if (_map_now_index >= _map_max_size)
	{
		return false;
	}
	for (int i = 0; i < _map_max_size; i++) {
		if (_map_table_ptr[i].key == key) {
			memset(_map_table_ptr[i].data, 0x00, data_size);
			sprintf_s(_map_table_ptr[i].data, "%s", data);
			return true;
		}
	}
	_map_table_ptr[_map_now_index].key = key;
	sprintf_s(_map_table_ptr[_map_now_index].data, "%s", data);
	_map_now_index++;
	return true;
}

char* CMap::find(uint32_t key) {
	for (int i = 0; i < _map_max_size; i++) {
		if (_map_table_ptr[i].key == key) {
			return _map_table_ptr[i].data;
		}
	}
	return (char*)"";
}

void CMap::remove(uint32_t key) {
	uint16_t remove_key_index = 0;
	for (int i = 0; i < _map_max_size; i++) {
		if (_map_table_ptr[i].key == key) {
			memset(_map_table_ptr[i].data, 0x00, data_size);
			_map_table_ptr[i].key = 0;
			remove_key_index = i;
			_map_now_index--;
			break;
		}	
	}
	for (int i = remove_key_index; i < _map_max_size - 1; i++) {
		memcpy(_map_table_ptr[i].data, _map_table_ptr[i + 1].data, data_size);
		_map_table_ptr[i].key = _map_table_ptr[i + 1].key;
	}
}

uint16_t CMap::sizeLeft() {
	return _map_max_size - _map_now_index;
}



#endif //_CMAP_H_