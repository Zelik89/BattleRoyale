[EntityEditorProps(category: "BattleRoyale/Zone Point", description: "BattleRoyale Zone Point")]
class BR_ZonePointClass : SCR_PositionClass
{
}

class BR_ZonePoint : SCR_Position
{
	protected static ref array<BR_ZonePoint> m_ZonePoints = {};

	//------------------------------------------------------------------------------------------------
	static BR_ZonePoint GetRandomPoint()
	{
		if (m_ZonePoints.IsEmpty()) 
			return null;
		
		return m_ZonePoints.GetRandomElement();
	}
	//------------------------------------------------------------------------------------------------
	static array<BR_ZonePoint> GetPoints()
	{
		return m_ZonePoints;
	}

	//------------------------------------------------------------------------------------------------
	#ifdef WORKBENCH
	override void SetColorAndText()
	{
		m_sText = "BR Zone Point";
		m_iColor = Color.GREEN;
	}
	#endif
	//------------------------------------------------------------------------------------------------
	void BR_ZonePoint(IEntitySource src, IEntity parent)
	{
		//SetFlags(EntityFlags.STATIC, true);

		if (GetGame().InPlayMode()) 
			m_ZonePoints.Insert(this);
	}

	//------------------------------------------------------------------------------------------------
	void ~BR_ZonePoint()
	{
		if (m_ZonePoints) 
			m_ZonePoints.RemoveItem(this);
	}
}
