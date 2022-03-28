package com.kesar.a.test;

import com.kesar.a.*;

public class Test extends AStar {

	public static void main(String[] args)
	{
		int[][] maps = {
				{ 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 1, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 1, 1, 1, 1 },
				{ 0, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0, 0, 0, 0 }
				};
		MapInfo info=new MapInfo(maps,maps[0].length, maps.length,new Node(7, 0), new Node(0, 4));
		//new AStar().start(info);
		//new Dijkstra().start(info);
		new Bfs().start(info);
		printMap(maps);
	}
	
	/**
	 * 打印地图
	 */
	public static void printMap(int[][] maps)
	{
		for (int i = 0; i < maps.length; i++)
		{
			for (int j = 0; j < maps[i].length; j++)
			{
				System.out.print(maps[i][j] + " ");
			}
			System.out.println();
		}
	}

}
