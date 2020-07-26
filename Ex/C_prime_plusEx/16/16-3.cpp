# include <stdio.h>
# include <math.h>
# define RAD_TO_DEG (180 / (4 * atan(1)))  //最外部最好用（）起来 
struct polar {
	float len;
	float angle;
};

struct rect {
	float x;
	float y;
};

struct rect polar_to_rect(struct polar st);
int main(void)
{
	struct polar Polar = {45, 60};
	struct rect ret;

	
	ret = polar_to_rect(Polar);
	printf("Polar: (%.2f, %.2f) to Rect: (%.2f, %.2f)",
				Polar.len, Polar.angle, ret.x, ret.y);
	return 0;
}

struct rect polar_to_rect(struct polar st)
{
	struct rect tmp;
	float hudu = (float)((int)st.angle % 360) / RAD_TO_DEG;
	tmp.x = st.len * cosf(hudu);
	tmp.y = st.len * sinf(hudu);
	
	return tmp;
}


