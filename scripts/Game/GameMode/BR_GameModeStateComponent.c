[ComponentEditorProps(category: "BattleRoyale/GameMode/Components", description: "Game Mode component responsible for controlling the main game state.")]
class BR_GameModeStateComponentClass : SCR_GameGameModeStateComponentClass
{
}

//! Game mode component that handles the game duration.
class BR_GameModeStateComponent : SCR_GameGameModeStateComponent
{
	
	int SizeIndex ;
	override void OnStateEntered()
	{

		BR_ZonePoint ZonePoint = BR_ZonePoint.GetRandomPoint();
		vector StartPosition = ZonePoint.GetOrigin();
		Resource Prefab = Resource.Load("{B1AA09E9A84A5BEF}Prefabs/MP/Zone/BR_Zone.et");
		BR_ZoneTriggerEntity Zone = BR_ZoneTriggerEntity.Cast(GetGame().SpawnEntityPrefab(Prefab,GetGame().GetWorld()));
		SizeIndex = Zone.GetSphereRadius();
		Zone.SetOrigin(StartPosition);
		Zone.Update();

		SCR_EntityHelper.DeleteEntityAndChildren(ZonePoint);
		ZonePoint = BR_ZonePoint.GetRandomPoint();
		StartPosition = ZonePoint.GetOrigin();
		GetGame().GetCallqueue().CallLater(SetOrigin,1,true,Zone,StartPosition);
		SCR_EntityHelper.DeleteEntityAndChildren(ZonePoint);


	}

	void SetOrigin(BR_ZoneTriggerEntity Zone,vector StartPosition)
	{
		if(Zone.GetOrigin() == StartPosition)
		{
			GetGame().GetCallqueue().Remove(SetOrigin);
			SizeIndex = SizeIndex*0.75;
			Print(SizeIndex);
			GetGame().GetCallqueue().CallLater(SetSize,1000,true,Zone,SizeIndex);
			return;
		}

		vector NewPosition = SCR_Math3D.MoveTowards(Zone.GetOrigin(), StartPosition,0.1);
		Zone.SetOrigin(NewPosition);
		Zone.Update();	

	}
	
	void SetSize(BR_ZoneTriggerEntity Zone, float Size)
	{
		float OldSize = Zone.GetSphereRadius(); 
		
		if(Zone.GetSphereRadius() == Size)
		{
			GetGame().GetCallqueue().Remove(SetSize);
			BR_ZonePoint ZonePoint = BR_ZonePoint.GetRandomPoint();
			if(!ZonePoint)
				return;
			vector StartPosition = ZonePoint.GetOrigin();
			SCR_EntityHelper.DeleteEntityAndChildren(ZonePoint);
			GetGame().GetCallqueue().CallLater(SetOrigin,1,true,Zone,StartPosition);			
			return;
		}	
			
		Zone.SetSphereRadius(OldSize - 1.0);
		Zone.SetScale(Zone.GetSphereRadius()*2);
		Zone.Update();			
	}
	
	
	
	
}
