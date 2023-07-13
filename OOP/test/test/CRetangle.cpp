#include "CRetangle.h"
void CRetangle::setWidth(int width) {
	this->width = width;
}
void CRetangle::setHeight(int _height) {
	this->height = _height;
}
int CRetangle::getWidth() {
	return width;
}
int CRetangle::getHeight() {
	return height;
}
int CRetangle::area() {
	return width * height;
}