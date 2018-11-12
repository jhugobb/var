#ifndef vector_h
#define vector_h

class Vector {
    private:
        double m_x;
        double m_y;
        double m_z;
	
    public: 
		Vector();
        Vector(const Vector& v);
        Vector(double x, double y, double z);
        
        inline double vx() {return m_x;};
        inline double vy() {return m_y;};
        inline double vz() {return m_z;};
        
        inline void vx(double x) { m_x=x;};
        inline void vy(double y) { m_y=y;};
        inline void vz(double z) { m_z=z;};
        
		float norm();
		void normalize();
		Vector crossProduct(Vector& v);
		Vector operator-(Vector& u);
	
};

#endif /* vector_h */
