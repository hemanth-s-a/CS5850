class vertex {
	double x;
	double y;
	double z;
};

class shape {
	public:
	virtual create
};


class boundingBox{
	vertex min;
	vertex max;
	public:
	
	void add_vertex(vertex v){
		if(min.x > v.x)
			min.x = v.x;
		if(max.x < v.x)
			max.x = v.x;
			
		if(min.y > v.y)
			min.y = v.y;
		if(max.y < v.y)
			max.y = v.y;
			
		if(min.z > v.z)
			min.z = v.z;
		if(max.z < v.z)
			max.z = v.z;
	}
	
	bool detect_collision(boundingBox b1){
	
		if(this.min.x <= b1.min.x <= this.max.x || this.min.x <= b1.man.x <= this.max.x ) {
			if(this.min.y <= b1.min.y <= this.max.y || this.min.y <= b1.man.y <= this.max.y ) {
				if(this.min.z <= b1.min.z <= this.max.z || this.min.z <= b1.man.z <= this.max.z ) {
					return true;
				}
			}
		}
		return false;
	}
	

};


class cube {
	vertex center;
	double length;
	boundingBox box;
	public:
	
	cube(double x,double y,double z):vertex(x,y,z){
			build_bounding_box();
	}
	
	void build_boundingbox(){
		
	}
	
	boundingBox get_bounding_box(){
		return box
	}
	
	bool check_collision (cube *c1) {
		return box.detect_collision(c1->box);
	}
	
	
	
};