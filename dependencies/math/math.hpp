#pragma once
constexpr double pi = 3.14159265358979323846;

namespace math {
	void correct_movement(vec3_t old_angles, c_usercmd* cmd, float old_forwardmove, float old_sidemove);
	void angle_vectors_alternative(const vec3_t& angles, vec3_t* forward);
	void vector_angles_alternative(const vec3_t& forward, vec3_t& angles);
	vec3_t calculate_angle(vec3_t& a, vec3_t& b);
	vec3_t calculate_angle2(const vec3_t& source, const vec3_t& destination, const vec3_t& viewAngles);
	void sin_cos(float r, float* s, float* c);
	vec3_t angle_vector(vec3_t angle);
	void transform_vector(vec3_t&, matrix_t&, vec3_t&);
	void vector_angles(vec3_t&, vec3_t&);
	void angle_vectors(vec3_t&, vec3_t*, vec3_t*, vec3_t*);
	vec3_t vector_add(vec3_t&, vec3_t&);
	vec3_t normalize_aimbot();
	vec3_t vector_subtract(vec3_t&, vec3_t&);
	vec3_t vector_multiply(vec3_t&, vec3_t&);
	vec3_t vector_divide(vec3_t&, vec3_t&);
	bool screen_transform(const vec3_t& point, vec3_t& screen);
	bool world_to_screen(const vec3_t& origin, vec3_t& screen);

	int clamp(double v, double min, double max);
};