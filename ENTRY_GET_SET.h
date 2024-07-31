//AREA
//getters
	unsigned char shape(){return entry.vals.shape;}
	unsigned char type(){return entry.vals.type;}
	unsigned char came_index(){return entry.vals.came_index;}
	unsigned char priority(){return entry.vals.priority;}
	float* pos(){return entry.vals.pos;}
	float* rot(){return entry.vals.rot;}
	float* scale(){return entry.vals.scale;}
	unsigned short setting1(){return entry.vals.setting1;}
	unsigned short setting2(){return entry.vals.setting2;}
	unsigned char route_id(){return entry.vals.route_id;}
	unsigned char enemy_id(){return entry.vals.enemy_id;}
	unsigned short padding(){return entry.vals.padding;}
	//setters
	void shape(unsigned char i){entry.vals.shape=i;}
	void type(unsigned char i){entry.vals.type=i;}
	void came_index(unsigned char i){entry.vals.came_index=i;}
	void priority(unsigned char i){entry.vals.priority=i;}
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void rot(float x, float y, float z){entry.vals.rot[0]=x; entry.vals.rot[1]=y; entry.vals.rot[2]=z;}
	void scale(float x, float y, float z){entry.vals.scale[0]=x; entry.vals.scale[1]=y; entry.vals.scale[2]=z;}
	void setting1(unsigned short i){entry.vals.setting1=i;}
	void setting2(unsigned short i){entry.vals.setting2=i;}
	void route_id(unsigned char i){entry.vals.route_id=i;}
	void enemy_id(unsigned char i){entry.vals.enemy_id=i;}
	void padding(unsigned short i){entry.vals.padding=i;}
//CAME
//getters
	unsigned char type(){return entry.vals.type;}
	unsigned char next(){return entry.vals.next;}
	unsigned char camshake(){return entry.vals.camshake;}
	unsigned char route(){return entry.vals.route;}
	unsigned short velo_point(){return entry.vals.velo_point;}
	unsigned short velo_zoom(){return entry.vals.velo_zoom;}
	unsigned short velo_view(){return entry.vals.velo_view;}
	unsigned char startflag(){return entry.vals.startflag;}
	unsigned char movieflag(){return entry.vals.movieflag;}
	float* pos(){return entry.vals.pos;}
	float* rot(){return entry.vals.rot;}
	float zoomstart(){return entry.vals.zoomstart;}
	float zoomend(){return entry.vals.zoomend;}
	float* start_vector(){return entry.vals.start_vector;}
	float* end_vector(){return entry.vals.end_vector;}
	float time(){return entry.vals.time;}
	//setters
	void type(unsigned char i){entry.vals.type=i;}
	void next(unsigned char i){entry.vals.next=i;}
	void camshake(unsigned char i){entry.vals.camshake=i;}
	void route(unsigned char i){entry.vals.route=i;}
	void velo_point(unsigned short i){entry.vals.velo_point=i;}
	void velo_zoom(unsigned short i){entry.vals.velo_zoom=i;}
	void velo_view(unsigned short i){entry.vals.velo_view=i;}
	void startflag(unsigned char i){entry.vals.startflag=i;}
	void movieflag(unsigned char i){entry.vals.movieflag=i;}
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void rot(float x, float y, float z){entry.vals.rot[0]=x; entry.vals.rot[1]=y; entry.vals.rot[2]=z;}
	void zoomstart(float i){entry.vals.zoomstart=i;}
	void zoomend(float i){entry.vals.zoomend=i;}
	void start_vector(float x, float y, float z){entry.vals.start_vector[0]=x; entry.vals.start_vector[1]=y; entry.vals.start_vector[2]=z;}
	void end_vector(float x, float y, float z){entry.vals.end_vector[0]=x; entry.vals.end_vector[1]=y; entry.vals.end_vector[2]=z;}
	void time(float i){entry.vals.time=i;}
//CKPT
//getters
	float* lpoint(){return entry.vals.lpoint;}
	float* rpoint(){return entry.vals.rpoint;}
	unsigned char respawn_pos(){return entry.vals.respawn_pos;}
	unsigned char type(){return entry.vals.type;}
	unsigned char prev(){return entry.vals.prev;}
	unsigned char next(){return entry.vals.next;}
	//setters
	void lpoint(float x, float z){entry.vals.lpoint[0]=x; entry.vals.lpoint[1]=z;}
	void rpoint(float x, float z){entry.vals.rpoint[0]=x; entry.vals.rpoint[1]=z;}
	void respawn_pos(unsigned char i){entry.vals.respawn_pos=i;}
	void type(unsigned char i){entry.vals.type=i;}
	void prev(unsigned char i){entry.vals.prev=i;}
	void next(unsigned char i){entry.vals.next=i;}
//ENPT
//getters
	float* pos(){return entry.vals.pos;}
	float bound(){return entry.vals.bound;}
	unsigned short set1(){return entry.vals.set1;}
	unsigned char set2(){return entry.vals.set2;}
	unsigned char set3(){return entry.vals.set3;}
	//setters
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void bound(float i){entry.vals.bound=i;}
	void set1(unsigned short i){entry.vals.set1=i;}
	void set2(unsigned char i){entry.vals.set2=i;}
	void set3(unsigned char i){entry.vals.set3=i;}
//GOBJ
//getters
	unsigned short id(){return entry.vals.id;}
	unsigned short padding(){return entry.vals.padding;}
	float* pos(){return entry.vals.pos;}
	float* rot(){return entry.vals.rot;}
	float* scale(){return entry.vals.scale;}
	unsigned short route(){return entry.vals.route;}
	unsigned short* setting(){return entry.vals.settings;}
	unsigned short presence(){return entry.vals.presence;}
	//setters
	void id(unsigned short i){entry.vals.id=i;}
	void padding(unsigned short i){entry.vals.padding=i;}
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void rot(float x, float y, float z){entry.vals.rot[0]=x; entry.vals.rot[1]=y; entry.vals.rot[2]=z;}
	void scale(float x, float y, float z){entry.vals.scale[0]=x; entry.vals.scale[1]=y; entry.vals.scale[2]=z;}
	void route(unsigned short i){entry.vals.route=i;}
	void setting(unsigned short i, unsigned short index){entry.vals.settings[index]=i;}
	void presence(unsigned short i){entry.vals.presence=i;}
//ITPT
//getters
	float* pos(){return entry.vals.pos;}
	float bound(){return entry.vals.bound;}
	unsigned short set1(){return entry.vals.set1;}
	unsigned short set2(){return entry.vals.set2;}
	//setters
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void bound(float i){entry.vals.bound=i;}
	void set1(unsigned short i){entry.vals.set1=i;}
	void set2(unsigned short i){entry.vals.set2=i;}
//KTPT
//getters
	unsigned short padding(){return entry.vals.padding;}
	float* pos(){return entry.vals.pos;}
	float* rot(){return entry.vals.rot;}
	short index(){return entry.vals.index;}
	//setters
	void padding(unsigned short i){entry.vals.padding=i;}
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void rot(float x, float y, float z){entry.vals.rot[0]=x; entry.vals.rot[1]=y; entry.vals.rot[2]=z;}
	void index(short i){entry.vals.index=i;}
//POTI
//getters
	unsigned short count(){return entry.vals.count;}
	unsigned char smooth(){return entry.vals.smooth;}
	unsigned char cyclic(){return entry.vals.cyclic;}
	std::vector<route_pt> path(){return route;}
	//setters
	void count(unsigned short i){entry.vals.count=i;}
	void smooth(unsigned char i){entry.vals.smooth=i;}
	void cyclic(unsigned char i){entry.vals.cyclic=i;}
	void path(const std::vector<route_pt> &r){route=r;}
	
	//getters
	float* pos(){return entry.vals.pos;}
	unsigned short speed(){return entry.vals.speed;}
	unsigned short setting(){return entry.vals.setting;}
	//setters
	void pos(float x, float y, float z){entry.vals.pos[0]=x; entry.vals.pos[1]=y; entry.vals.pos[2]=z;}
	void speed(unsigned short i){entry.vals.speed=i;}
	void setting(unsigned short i){entry.vals.setting=i;}
//XXPH
//getters
	char start(){return entry.vals.start;}
	char count(){return entry.vals.count;}
	char* from(){return entry.vals.from;}
	char* to(){return entry.vals.to;}
	short padding(){return entry.vals.padding;}
	//setters
	void start(char i){entry.vals.start=i;}
	void count(char i){entry.vals.count=i;}
	void from(char i, unsigned short index){entry.vals.from[index]=i;}
	void to(char i, unsigned short index){entry.vals.to[index]=i;}
	void padding(short i){entry.vals.padding=i;}
