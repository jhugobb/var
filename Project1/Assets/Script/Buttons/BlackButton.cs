using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlackButton : MonoBehaviour {

    private Vector3 lastPosition;
    private float spinForce = 150;
    private AudioSource source;
    public AudioClip shootSound;

    // Use this for initialization
    void Start () {
        lastPosition = new Vector3(58.5f, 1, -66.1f);
        source = GameObject.FindGameObjectWithTag("audio").GetComponent<AudioSource>();
    }
	
	// Update is called once per frame
	void Update () {
        transform.Rotate(0, spinForce * Time.deltaTime, 0);
    }

    public void Toggle()
    {
        source.PlayOneShot(shootSound, 1f);
        GameObject player = GameObject.FindGameObjectWithTag("Player");
        Vector3 playerPosition = player.transform.position;
        player.transform.position = lastPosition;
        lastPosition = playerPosition;
    }
}
