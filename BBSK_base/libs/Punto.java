package libs;

public class Punto{
	private long x;
	private long y;
	public Punto(long x, long y){
		this.x = x;
		this.y = y;
	}
	
	public long getX(){
		return x;
	}
	
	public long getY(){
		return y;
	}
	
	public boolean equals(Object o) {
		if (o == this) {
		  return true;
		}
		if (!(o instanceof Punto)) {
		  return false;
		}
		Punto p = (Punto)o;
		return p.getX() == this.getX() && p.getY() == this.getY();
    } 
	
	
}