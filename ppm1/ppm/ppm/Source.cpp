#include<iostream>
#include<fstream>
#include"vec3.h";
#include"ray.h";
using namespace std;



vec3 Color(const Ray& r) {
	vec3 unit_direction = unit_vector(r.Direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t * vec3(1, 0, 0);
}

int main() {
	ofstream outfile;
	outfile.open("test.ppm");

	int nx = 1200;
	int ny = 800;
	int ns = 10;
	outfile << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);

	for (int j = nx - 1; j >= 0; j--)
	{
		for (int i = 0; i < ny ; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(nx);
			Ray ra(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 col = Color(ra);

			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);
			outfile << ir << " " << ig << " " << ib << "\n";
		} 
	}


	outfile.close();
}