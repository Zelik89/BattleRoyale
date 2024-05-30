[EntityEditorProps(category: "BattleRoyale/Zone", description: "BattleRoyale Zone")]
class BR_ZoneTriggerEntityClass: BaseGameTriggerEntityClass{}
class BR_ZoneTriggerEntity : BaseGameTriggerEntity
{
	ref array<IEntity> m_PointsInside = {};
	//------------------------------------------------------------------------------------------------
	override protected void OnActivate(IEntity ent)
	{
		Print(ent);
	}
	//------------------------------------------------------------------------------------------------	
	override protected void OnDeactivate(IEntity ent)
	{

	}
	//------------------------------------------------------------------------------------------------	
	override protected void EOnInit(IEntity owner)
	{
		SetScale(GetSphereRadius()*2);
	}

	//------------------------------------------------------------------------------------------------
	void BR_ZoneTriggerEntity(IEntitySource src, IEntity parent)
	{
		SetEventMask(EntityEvent.INIT);
		
	}		
}