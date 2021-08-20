#include "number.hpp"

Number::Number(glm::vec2 position, int value, Quad** digits) {
	this->digits = digits;
	this->position = position;
	this->value = value;
}
void Number::setValue(int value) {
	this->value = value;
}
void Number::render(ShaderManager* shaderMan, std::string const& programName) {
	int firstDigit = value % 10;
	int tenthDigit = (value % 100) / 10;
	this->digits[firstDigit]->position = glm::vec2(this->position.x + 14, this->position.y);
	this->digits[firstDigit]->render(shaderMan, programName);
	this->digits[tenthDigit]->position = glm::vec2(this->position.x - 14, this->position.y);
	this->digits[tenthDigit]->render(shaderMan, programName);
}