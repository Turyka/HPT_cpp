#pragma once


// az elsõ pozícióban (tomb[0]) nem tárolunk értéket
// a tomb[ures_pozicio] az elsõ hely, ahol már nem tárolunk értéket
template <class Type>
class vektor {
	Type tomb[100];
	int ures_pozicio;
public:
	vektor() {
		ures_pozicio = 1;
		tomb[0] = Type();
	}

	void push_back(Type value) {
		tomb[ures_pozicio] = value;
		ures_pozicio++;
	}

	class Iterator {
		Type *index;
	public:
		Iterator(Type *_item = nullptr) : index(_item) {}
		bool operator == (const Iterator &other) const { return index == other.index; }
		bool operator != (const Iterator &other) const { return index != other.index; }
		
		Iterator operator++(int) {
			Iterator ret(index);
			index++;
			return ret;
		}
		Iterator& operator++() { 
			index++; 
			return *this;
		}
		Type& operator*() { return *index; }
	};

	Iterator begin() { return Iterator(&tomb[1]); }
	Iterator end() { return Iterator(&tomb[ures_pozicio]); }

	// KÉSZÍTSE EL A REVERSEITERATOR-T
	class ReverseIterator {
		Type *index;
		friend class Vektor;
	public:
		ReverseIterator(Type* _item = nullptr) : index(_item) {}
		bool operator == (const ReverseIterator& other) const { return index == other.index; }
		bool operator != (const ReverseIterator& other) const { return index != other.index; }
		ReverseIterator operator++(int) { // Post-increment
			ReverseIterator temp(index);
			--index;
			return temp;
		}
		ReverseIterator& operator++() { // Pre-increment
			--index;
			return *this;
		}
		Type& operator*() { return *index; }
	};

	// KÉSZÍTSE EL AZ RBEGIN ÉS REND FÜGGVÉNYEKET
	ReverseIterator rbegin() {
		return ReverseIterator(&tomb[ures_pozicio - 1]);
	}
	ReverseIterator rend() {
		return ReverseIterator(&tomb[0]);
	}
};