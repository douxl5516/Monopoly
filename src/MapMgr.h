#ifndef MAP_MGR_H
#define MAP_MGR_H

class Map;
class MapMgr
{
public:
private:
	MapMgr() {}
	MapMgr(const MapMgr&) {}
	MapMgr& operator=(const MapMgr&) = delete;
public:
	~MapMgr();
	static MapMgr* getInstance();
	static Map* getCurMap();
	static void release();
	void createMap();
private:
	static MapMgr* instance;
	static Map* curMap;
};



#endif