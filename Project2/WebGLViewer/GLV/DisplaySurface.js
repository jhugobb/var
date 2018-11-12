// Class DisplaySurface: walls of a projection-based system 
 
DisplaySurface = function(orig, uvector, vvector){  
    this.origin = orig; // Vec3 - Origin of the display 
    this.u = uvector;   // Vec3 - Horizontal vector 
    this.v = vvector;   // Vec3 - Vertical vector 
}; 
 
// Functions 
 
DisplaySurface.prototype.viewingMatrix = function(eye){ 
    var mat = new Mat4(); 
    mat.loadIdentity(); 
    a = new Vec3(this.u.x, this.u.y,this.u.z); 
    a = a.normalize(); 
    b = new Vec3(this.v.x, this.v.y,this.v.z); 
    b = b.normalize(); 
    c = Vec3.cross(a,b); 
     
    focus = Vec3.subtract(eye, c); 
    normal = new Vec3(0, eye.y,0); 
    mat.lookAt(eye, focus,normal); 
    return mat; 
}; 
 
DisplaySurface.prototype.projectionMatrix = function(eye, znear, zfar){ 
    var mat = new Mat4(); 
    mat.loadIdentity(); 
    var left, right, top, bottom; 
	var horizontalDistance=this.u.norm()/2;
    u = new Vec3(this.u.x, this.u.y,this.u.z); 
    u = u.normalize(); 
	var vertitalDistance=this.v.norm()/2;
    v = new Vec3(this.v.x, this.v.y,this.v.z); 
    v = v.normalize(); 
    n = Vec3.cross(u,v); 
     
    // Dot products needed 
    var uDOTe = Vec3.dot(u, eye); 
    var vDOTe = Vec3.dot(v, eye); 
    var nDOTe = Vec3.dot(n, eye); 
 
    // Calculating the distances of the display-dependent frustum 
    left=-znear*(horizontalDistance+uDOTe)/(horizontalDistance+nDOTe); 
    right=znear*(horizontalDistance-uDOTe)/(horizontalDistance+nDOTe); 
    top=-znear*(vertitalDistance+vDOTe)/(vertitalDistance+ nDOTe); 
    bottom=znear*(vertitalDistance-vDOTe)/(vertitalDistance+nDOTe); 
             
    mat.frustum(left, right, top, bottom, znear, zfar); 
 
    return mat; 
}; 