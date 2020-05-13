class DiscordObject_Image : DiscordObject
{
	/*
		https://discord.com/developers/docs/resources/channel#embed-object-embed-image-structure

		Fields:
			url - String
			proxy_url - string
			width - int
			height - int
	*/
	private int m_width;
	private int m_height;

	void DiscordFooter_Footer(int width = -1, int height = -1)
	{
		m_width = width;
		m_height = height;
	}
	
	override string DefaultJSONConvert()
	{
		return ConvertToJsonCloseByObject();
	}
	
	override protected string ConvertSpecialFields()
	{
		string addedFieldsToJson = "";
		
		addedFieldsToJson += GetWidthField();
		addedFieldsToJson += GetHeightField();
		return addedFieldsToJson;
	}
	
	private string GetWidthField()
	{
		if (m_width > -1)
		{
			return helperJSON.GetJSONLineOthers("width", m_width.ToString());
		}
		return "";
	}
	
	private string GetHeightField()
	{
		if (m_height > -1)
		{
			return helperJSON.GetJSONLineOthers("height", m_height.ToString());
		}
		return "";
	}

	override protected bool CanSetKey(string key)
	{
		switch (key)
		{
			case "url":
				return true;
			case "proxy_url":
				return true;
		}
		return false;
	}
};