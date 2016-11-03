class GameObject {
	public:
		GameObject();

		int getID() const;

	private:
		int id;
		static int currentID;
};
